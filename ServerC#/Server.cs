using System;
using System.Net;
using System.Net.Sockets;

namespace finalsocket
{
    class Server
    {
        TcpClient client;
        TcpListener tcpListener;
        NetworkStream stream;
        Int32 port;
        IPAddress iPAddress;
        byte[] bytes;
        String data;
        int i;

        byte[] Key = { 182, 131, 35, 156, 149, 66, 53, 237, 238, 163, 214, 71, 31, 10, 30, 124, 156, 226, 105, 111, 253, 124, 38, 72, 234, 126, 230, 5, 39, 37, 121, 230 };
        byte[] IV = { 1, 64, 119, 95, 10, 132, 5, 137, 103, 8, 100, 14, 91, 34, 81, 197 };

        public Server(string ip, Int32 prt)
        {
            iPAddress = IPAddress.Parse(ip);
            port = prt;

            // Buffer for reading data
            byte[] bytes = new Byte[256];
            data = null;
        }

        // Listen to client
        public void startListening()
        {
            try
            {
                // TcpListener server = new TcpListener(port);
                tcpListener = new TcpListener(iPAddress, port);

                // Start listening for client requests.
                tcpListener.Start();

                Console.Write("Waiting for a connection... ");

                // Perform a blocking call to accept requests.
                // You could also user server.AcceptSocket() here.
                client = tcpListener.AcceptTcpClient();
                Console.WriteLine("Connected!");

                // Get a stream object for reading and writing
                stream = client.GetStream();

                bytes = new Byte[16];

                // Loop to receive all the data sent by the client.
                while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
                {
                    // deleteZero(byte[] variable) for delete null elements.
                    var newbytes = deleteZeroBytes(bytes);
                    if (newbytes.Length == 0) break;

                    // Decrypt message
                    string decryptMSG = AES.Decrypt(newbytes, Key, IV);

                    Console.WriteLine("Received: {0}", decryptMSG);

                    // Process the data sent by the client.
                     string responseData = decryptMSG.ToUpper();
                 
                     // Encrypt response response
                     byte[] encryptMessage = AES.Encrypt(responseData, Key,IV);
                 
                     // Send response to client 
                     stream.Write(encryptMessage, 0, encryptMessage.Length);
                 
                     Console.WriteLine("Sent: {0}", responseData);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("ERROR: " + e.Message);
            }
        }

        // deleteZero(byte[] variable) for delete null elements.
        public byte[] deleteZeroBytes(byte[] packet)
        {
            var i = packet.Length - 1;
            while (packet[i] == 0)
            {
                --i;
            }
            var temp = new byte[i + 1];
            Array.Copy(packet, temp, i + 1);

            return temp;
        }
    }
}
