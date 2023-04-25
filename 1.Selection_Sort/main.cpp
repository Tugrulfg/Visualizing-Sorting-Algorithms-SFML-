#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<ctime> 

using namespace sf;

void set(RectangleShape shapes[],int size,int arr[]){		// Setting columns according to array elements
    for(int i=0;i<size;i++){
        shapes[i].setSize(Vector2f(15.f,arr[i]));
        shapes[i].setPosition(float(i*15+100),float(700-arr[i]));
        shapes[i].setFillColor(Color::White);
    }
}

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1000,700), "Selection Sort");
    window.setFramerateLimit(60);

    const int size=50;
    int arr[size];
    for(int l=0;l<size;l++)						// Setting array with random numbers between 1-650
        arr[l]=rand()%650 +1;
    int i,j,min,temp,flag=0;

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
            for(i=0;i<size-1;i++){					// Selection sort algorithm
                min=i;
                for(j=i+1;j<size;j++){
                    if(arr[j]<arr[min])
                       min=j;
                }
                temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
                    
                set(shapes,size,arr);
                window.clear(Color::Black);				// Clearing window
                for(int k=0;k<size;k++)				// Drawing all columns
                    window.draw(shapes[k]);
                window.display();					// Displaying window
                sleep(milliseconds(100));
                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed){		// Checking for closing window
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
