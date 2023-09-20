#include <iostream>
int check(int guy; int pole){
    int success=0;
    for(int i=0; i<3; i++){
        for(int h=0; h<2; h++){
            for(int j=h+1; j<3; j++){
                if(pole[i][h]==guy and pole[i][j]==guy){
                    if(h==0 and j==1){
                        if(pole[i][2]==0){
                            pole[i][2]=2;
                            success=1;
                            break;
                            break;
                            break;
                        } else if(h==0 and j==2){
                            if(pole[i][1]==0){
                                pole[i][1]=2;
                                success=1;
                                break;
                                break;
                                break;
                            }
                        } else{
                            if(pole[i][0]==0){
                                pole[i][0]=2;
                                success=1;
                                break;
                                break;
                                break;
                            }
                        }
                    } else if(pole[h][i]==guy and pole[j][i]==guy){
                        if(h==0 and j==1){
                            if(pole[2][i]==0){
                                pole[2][i]=2;
                                success=1;
                                break;
                                break;
                                break;
                            }
                        } else if(h==0 and j==2){
                            if(pole[1][i]==0){
                                pole[1][i]=2;
                                success=1;
                                break;
                                break;
                                break;
                            }
                        } else{
                            if(pole[0][i]==0){
                                pole[0][i]=2;
                                success=1;
                                break;
                                break;
                                break;
                            }
                        } else if(i!=1){
                            if(pole[i][i]==guy and pole[abs(i-j)][abs(i-j)]==guy){
                                if(h==0 and j==1){
                                    if(pole[2][2]==0){
                                        pole[2][2]=2;
                                        success=1;
                                        break;
                                        break;
                                        break;
                                    }
                                } else if(h==0 and j==2){
                                    if(pole[1][1]==0){
                                        pole[1][1]=2;
                                        success=1;
                                        break;
                                        break;
                                        break;
                                    }
                                } else{
                                    if(pole[0][0]==0){
                                        pole[0][0]=2;
                                        success=1;
                                        break;
                                        break;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return success;
}
            
void AI(int turns; int pole){
    int status=0;
    if(turns==1){
        if(pole[1][1]==0){
            pole[1][1]=2;
        } else{
            pole[0][0]=2;
        }
    }else{
        status = check(1);
        if(status==0){
            status = check(2);
        }
        if(status==0){
            if(pole[0][1]==0){
                pole[0][1]=2;
            } else if(pole[1][0]==0){
                pole[1][0]=2;
            } else if(pole[1][2]==0){
                pole[1][2]=2;
            } else if(pole[2][1]==0){
                pole[2][1]=2;
            }
        }
    }
    turns++;
}


int main(){
    std::cout << "╭---┬---┬---╮\n";
    std::cout << "|   |   |   |\n";
    std::cout << "├---┼---┼---┤\n";
    std::cout << "|   |   |   |\n";
    std::cout << "├---┼---┼---┤\n";
    std::cout << "|   |   |   |\n";
    std::cout << "╰---┴---┴---╯\n";

    
}



