#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime> 

using namespace sf;

void set(RectangleShape shapes[],int size,int arr[]){			// Setting colums with array elements
    for(int i=0;i<size;i++){
        shapes[i].setSize(Vector2f(15.f,arr[i]));
        shapes[i].setPosition(float(i*15+100),float(700-arr[i]));
        shapes[i].setFillColor(Color::White);
    }
}

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1000,700), "Bubble Sort");
    window.setFramerateLimit(60);

    const int size=50;
    int arr[size];
    for(int l=0;l<size;l++)							// Filling array with random numbers between 1-650
        arr[l]=rand()%650 +1;
    int i,j,temp,flag=0;

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
            for(i=0;i<size;i++){						// Bubble sort algorithm
                for(j=0;j<size-i-1;j++){
                    if(arr[j]>arr[j+1]){
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                    set(shapes,size,arr);
                    window.clear(Color::Black);				// Clearing the window
                    for(int k=0;k<size;k++)					// Drawing all columns
                        window.draw(shapes[k]);
                    window.display();						// Displaying the window
                    while (window.pollEvent(event))
                    {
                        if (event.type == Event::Closed){			// Checking for closing the window
                            window.close();
                            return 0;	
                        }
                    }   
                }
            }
            flag=1; 
        }
        
    }

    return 0;
}
