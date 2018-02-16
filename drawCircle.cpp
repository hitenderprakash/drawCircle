#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > Raster(int radius, int scale){
	if(radius<=0){
		cout<<"\nInvalid Radius";
		vector<vector<char> > temp;
		return temp;
	}
	int rows=2*radius*scale +1;
	int cols=2*2*radius*scale +1;
	int mid_h=cols/2;
	int mid_v=rows/2;
	vector<vector<char> > can(rows,vector<char>(cols,' '));
	
	for(int i=mid_h;i<cols;i=i+2){
		int cord_x=i;
		int cord_y;
		
		int x=(i-mid_h)/2;
		for(int j=0;j<=mid_v;j++){			
			int y=mid_v-j;
			if(y*y+x*x ==radius*radius){
				cord_y=j;
				break;
			}
			else if(y*y+x*x >(radius*radius)){
				continue;
			}
			else if(y*y+x*x <(radius*radius)){
				int delta1=(radius*radius)-(y*y + x*x);
				delta1=(delta1<0)?-delta1: delta1;
				
				int delta2=((y+1)*(y+1)+x*x)-(radius*radius);
				delta2=(delta2<0)?-delta2: delta2;
				
				cord_y=(delta1<=delta2)? j:j-1;
				break;
			}	
					
		}
		//mark the coordinate in matrix
		//in matrix y axis is along rows and x-axis along colum
		can[cord_y][cord_x]='*';
		
		//reflection in 4th quadrant
		can[rows-cord_y-1][cord_x]='*';
		//reflection in 2nd quadrant
		can[cord_y][cols-1-cord_x]='*';
		
		//reflection in 3rd quadrant
		can[rows-cord_y-1][cols-1-cord_x]='*';	
	}
	return can;
}

void Draw(vector<vector<char> > & vec){
	int rows=vec.size();
	if(rows==0){return;}
	int cols=vec[0].size();
	for(int i=0;i<rows;i++){
		cout<<"\n";
		for(int j=0;j<cols;j++){
			cout<<vec[i][j];
		}
	}
}

int main(){
	vector<vector<char> > canvas;
	canvas=Raster(10,1);
	Draw(canvas);
	cout<<"\n";
	return 0;
}
