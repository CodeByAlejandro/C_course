int counter;

int main(int argc, char **argv)
{
    extern void display(void); // extern is optional but clearly states it is not supposed to be defined in this file
	for (; counter < 5; counter++) {
        display();
    }
    
	return 0;
}
