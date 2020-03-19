if (counters * capacity < initialUserCount)
        {
            waitlist = insertAtEnd(NULL, counters * capacity + 1);
            for (int i = counters * capacity + 2; i <= initialUserCount; i++)
            {
                insertAtEnd(waitlist, i);
            }
        }