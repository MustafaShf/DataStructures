if (i > 0)
            {
                temp = Head[i];
                temp2 = Head[i - 1];
                while (temp && temp2)
                {
                    temp->up = temp2;
                    temp2->down = temp;
                    temp = temp->right;
                    temp2 = temp2->right;
                }