#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime> 

using namespace sf;

void set(RectangleShape shapes[],int size,int arr[]){			// Setting columns with array elements
    for(int i=0;i<size;i++){
        shapes[i].setSize(Vector2f(15.f,arr[i]));
        shapes[i].setPosition(float(i*15+100),float(700-arr[i]));
        shapes[i].setFillColor(Color::White);
    }
}

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1000,700), "Insertion Sort");
    window.setFramerateLimit(60);

    const int size=50;
    int arr[size];
    for(int l=0;l<size;l++)							// Filling array with random numbers between 1-650
        arr[l]=rand()%650 +1;
    int i,j,key,flag=0;

    RectangleShape shapes[size];      

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if(!flag){	
            for(i=1;i<size;i++){						// Insertion sort algorithm
                key=arr[i];
                j=i-1;
                while(j>=0&&arr[j]>key){
                    arr[j+1]=arr[j];
                    j=j-1;
                }
                arr[j+1]=key;

                set(shapes,size,arr);
                window.clear(Color::Black);					// Clearing the window
                for(int k=0;k<size;k++)					// Drawing the columns
                    window.draw(shapes[k]);			
                window.display();						// Displaying the window
                sleep(milliseconds(100));
                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed){			// Checking for closing the window
                        window.close();
                    	 return 0;
                    }
                }
            }
            flag=1; 
        }
        
    }

    return 0;
}
