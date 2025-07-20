_______________________________________________________________________
📡 MINITALK :
_______________________________________________________________________

The Minitalk project is a common assignment at 42/1337 school,
and it focuses on inter-process communication (IPC) using Unix signals.

_______________________________________________________________________
📡 What Is Minitalk ?:
_______________________________________________________________________

Minitalk is a small communication system where:

  * One program is the server.

  * Another program is the client.

  * The client sends text messages to the server bit by bit, using only Unix signals (SIGUSR1 and SIGUSR2).

_______________________________________________________________________
🎯 Goals of the Project:
_______________________________________________________________________

  * Understand how Unix signals work.

  * Implement a way for two processes to communicate without sockets or pipes.

  * Learn bitwise operations, signals, and asynchronous programming.

______________________________________________________________________
🧱 Project Structure :
______________________________________________________________________

You must write two programs:

✅ server :

  * Waits for messages from the client.

  * Reconstructs characters from the bits sent by the client using SIGUSR1 and SIGUSR2.

  * Displays the received message on the terminal.

✅ client :

  * Takes two arguments: the PID of the server and the string to send.

  * Sends the string to the server by encoding each bit using signals:

      SIGUSR1 = bit 0.

      SIGUSR2 = bit 1.

____________________________________________________________________
📥 Example Usage :
____________________________________________________________________

Start the server:

        ./server

You’ll see:

        Server PID: 12345

Now send a message:

        ./client 12345 "Hello world!"

The server should print:

        Hello, world!

_____________________________________________________________________
🔧 How It Works :
_____________________________________________________________________

🧠 Encoding Characters :

 Each character is 8 bits (1 byte). For example:

        'H' = 01001000

So the client sends:

        SIGUSR1 → bit 0 
        SIGUSR2 → bit 1  

Send 8 signals per character.

🧠 Receiving Characters :

 The server:

  * Handles each signal with a signal handler.

  * Reconstructs the byte one bit at a time.

  * Once 8 bits are collected → convert to character → print it.

_____________________________________________________________________
✍️ Important Functions :
_____________________________________________________________________

  * kill(pid, SIGUSR1/SIGUSR2) → send signal to another process.

  * signal() or sigaction()    → set up signal handlers.

  * getpid()                   → get your process PID.

  * usleep()                   → pause between sending signals (helps avoid signal loss).

____________________________________________________________________
🧠 Extra (Bonus Part) :
____________________________________________________________________

In the bonus part, you:

  * Must use sigaction() instead of signal().

  * Add support for sending messages back from server to client.

  * Add support for Unicode characters.

  * Make it multi-client safe.

____________________________________________________________________
✅ Evaluation Criteria :
____________________________________________________________________

   * Can send and receive messages.

   * Uses only SIGUSR1 and SIGUSR2.

   * No memory leaks.

   * Handles all characters properly.

   * Clean code and Makefile.

____________________________________________________________________
🧪 Example Output :
____________________________________________________________________

      $ ./server
      Server PID: 4321

      $ ./client 4321 "42 is awesome!"

Server prints:

      42 is awesome!
