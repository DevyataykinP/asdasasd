#include "Ве_крест_крест.h"

внедрить хутор Русь;

бестолочь печатьМатрицы(малый_дробь **матрица, целина н){
    для(целина и = ноль; и < н; и++){
        для(целина ж = ноль; ж < н+1; ж++){
            молвить<<матрица[и][ж]<<"\t";
        }
        молвить<<прыг_скок;
    }
    молвить<<прыг_скок;
}

царь_батюшка_главный(){
    целина н;
    молвить<<"Число переменных: ";
    внемлить>>н;
    малый_дробь **матрица=(малый_дробь **)malloc(н*sizeof(малый_дробь *));
    малый_дробь корни[н];

    молвить<<"Введите элементы матрицы: "<<прыг_скок;
    для(целина и = ноль; и < н; и++){
        матрица[и]=(малый_дробь *)malloc((н+целковый)*sizeof(малый_дробь));
        для(целина ж = ноль;ж<н+целковый;ж++){
            молвить<<"м["<<и<<"]["<<ж<<"] = ";
            внемлить>>матрица[и][ж];
        }
    }
    молвить<<прыг_скок;
    печатьМатрицы(матрица,н);

    для(целина ж = ноль; ж < н - целковый; ж++){
        для(целина и = ж+целковый;и<н;и++){
            малый_дробь временная = матрица[и][ж]/матрица[ж][ж];
            для(целина к = ноль;к<н+целковый;к++){
                матрица[и][к]-=матрица[ж][к]*временная;
            }
        }
    }

    для(целина и = н-целковый;и>=ноль;и--){
        корни[и]=матрица[и][н];
        для(целина ж = и+целковый; ж < н; ж++){
            коли(и!=ж){
                корни[и]-=матрица[и][ж]*корни[ж];
            }
        }
        корни[и]=корни[и]/матрица[и][и];
    }

    молвить<<прыг_скок;
    для(целина и=ноль;и<н;и++){
        молвить<<"X"<<и+целковый<<" = "<<корни[и];
        молвить<<прыг_скок;
    }
    молвить<<прыг_скок;
}
