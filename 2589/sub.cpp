#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int main() {
	 
	    char map[50][50]={0}; //지도
		    int dist[50][50]={0}; //특정 정점 기준으로 [y][x]까지의 거리
			    
			    int h,w; //y,x좌표
				    cin>>h>>w;
					    
					    queue<pair<int,int>> landQ; //출발 지점 모여있는 큐 (육지)
						    
						    for(int i=0;i<h;i++)
								        for(int j=0;j<w;j++){
											            cin>>map[i][j];
														            
														            //이동할 수 있는 육지
														            if(map[i][j]=='L')
																		                landQ.push(make_pair(i,j));
																	        }
							    
							 
							    int ans=0;
								    while(!landQ.empty()){
										        int land_y=landQ.front().first; //출발하는 y좌표
												        int land_x=landQ.front().second; //출발하는 x좌표
														        landQ.pop();
																        
																        memset(dist,0,sizeof(dist));
																		        
																		        queue<pair<int,int>> q;
																				        q.push(make_pair(land_y,land_x));
																						        
																						        //land_y, land_x를 기준으로 다른 육지까지 이동하는 거리 값 구하기
																						        while(!q.empty()){
																									            int y=q.front().first;
																												            int x=q.front().second;
																															            q.pop();
																																		            
																																		            for(int i=0;i<4;i++){
																																						                int ny=y+dy[i];
																																										                int nx=x+dx[i];
																																														                
																																														                if(ny<0 || ny>=h || nx<0 || nx>=w)
																																																			                    continue;
																																																		                
																																																		                //이동할 수 없는 바다이거나 출발 지역인 land_y,land_x로 다시 올 때
																																																		                if(map[ny][nx]=='W' || (land_y==ny && land_x==nx))
																																																							                    continue;
																																																						                
																																																						                //방문한 적 없거나 방문했을 때 더 짧게 오는 경로 존재 시
																																																						                if(!dist[ny][nx] || dist[ny][nx]>dist[y][x]+1){
																																																											                    dist[ny][nx]=dist[y][x]+1;
																																																																                    q.push(make_pair(ny,nx));
																																																																					                }
																																																										            }
																																					        }
																								        
																								        //land_y,land_x를 기준으로 이동할 수 있는 최대 거리 업데이트
																								        for(int i=0;i<h;i++)
																											            for(int j=0;j<w;j++)
																															                if(dist[i][j])
																																				                    ans=max(ans,dist[i][j]);
																										        
																										    }
									    
									    cout<<ans<<endl;
										    return 0;
}
