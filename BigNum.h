#ifndef BIGNUM_H
#define BIGNUM_H
using namespace std;


//КОНСТРУКТОР ПО УМОЛЧАНИЮ
    BigNum::BigNum(): sign(true){
    }

   //КОНСТРУКТОР КОПИРОВАНИЯ
    BigNum::BigNum(const BigNum& a): sign(a.sign){
        num = a.num;
    }

  //КОНСТРУКТОР ПО ИНТУ
    BigNum::BigNum(SMALLNUM x) {
        if (x < 0) {
            this->sign = false;
            x = -x;
        } else {
            this->sign = true;
        }
        if (x == 0) {
            this->num.push_back(0);
        }
        while (x > 0) {
            this->num.push_back(x % radix);
            x = x / radix;
        }
    }


   //ДЕСТРУКТОР
    BigNum::~BigNum() {
    }


    //ВВОД С КЛАВИАТУРЫ (! - КОНЕЦ ЧИСЛА)
    void BigNum::input() {
        short* buf = (short*) malloc (sizeof(short) * MAX_SIZE);
        int cap_buf = MAX_SIZE;
        int i=0;
        char c;
        std::cin>>c;
        if (c == '-'){
            this->sign = false;
            cin>>c;
        } else {
            this -> sign = true;
        }
        while (c == '0'){    // пропускает незначащие нули, введённые пользователем
            std::cin>> c;
        }
        if (c == '!') {
            this->num.push_back(0);
            free (buf);
            return;
        }
        switch (c) {
            case '1': buf[i] = 1;
                ++i;
                break;
            case '2': buf[i] = 2;
                ++i;
                break;
            case '3': buf[i] = 3;
                ++i;
                break;
            case '4': buf[i] = 4;
                ++i;
                break;
            case '5': buf[i] = 5;
                ++i;
                break;
            case '6': buf[i] = 6;
                ++i;
                break;
            case '7': buf[i] = 7;
                ++i;
                break;
            case '8': buf[i] = 8;
                ++i;
                break;
            case '9': buf[i] = 9;
                ++i;
                break;
            }
        bool flag = true;
        while (flag){
            std::cin>>c;
            switch (c) {
            case '1': buf[i] = 1;
                ++i;
                break;
            case '2': buf[i] = 2;
                ++i;
                break;
            case '3': buf[i] = 3;
                ++i;
                break;
            case '4': buf[i] = 4;
                ++i;
                break;
            case '5': buf[i] = 5;
                ++i;
                break;
            case '6': buf[i] = 6;
                ++i;
                break;
            case '7': buf[i] = 7;
                ++i;
                break;
            case '8': buf[i] = 8;
                ++i;
                break;
            case '9': buf[i] = 9;
                ++i;
                break;
            case '0': buf[i] = 0;
                ++i;
                break;
            case '!': flag = false;
                ++i;
                break;
            }
            if ( i == cap_buf) {
                buf = (short*) realloc(buf, cap_buf * 2 * sizeof(short));
            }
        }
        --i;//сейчас ровно столько, сколько цифр в числе
        int length_of_tail = i % radix_size;
        int x;
        for (int j = i-1; j >= length_of_tail; j-= radix_size) {
            x = 0;
            for (int q = 0; q < radix_size; ++q){
                x += (pow((float)X,  (int)q) * buf[j - q]);
            }
            this->num.push_back(x);
        }
        x = 0;
        for (int j = 0; j < length_of_tail; ++j){		//Работает
            x += (pow((float)X, (int) (length_of_tail -j-1)) * buf[j]);
        }
            if (x != 0) {
                this->num.push_back(x);

            }
        free(buf);
        return;
    }


    //ВВОД ИЗ ФАЙЛА (НЕ ЗАКРЫВАЕТ ФАЙЛ)

    void BigNum::finput (FILE *fp) {
        short* buf = (short*) malloc (sizeof(short) * MAX_SIZE);
        int cap_buf = MAX_SIZE;
        int i=0;
        char c;
        fscanf(fp, "%c", &c);
        if (c == '-'){
            this->sign = false;
            fscanf(fp, "%c", &c);
        } else {
            this -> sign = true;
        }
        while (c == '0'){    // пропускает незначащие нули, введённые пользователем
              fscanf(fp,"%c", &c);
        }
        if ((c == ' ')||(c == EOF)) {
            this->num.push_back(0);
            free (buf);
            return;
        }
        switch (c) {
            case '1': buf[i] = 1;
                ++i;
                break;
            case '2': buf[i] = 2;
                ++i;
                break;
            case '3': buf[i] = 3;
                ++i;
                break;
            case '4': buf[i] = 4;
                ++i;
                break;
            case '5': buf[i] = 5;
                ++i;
                break;
            case '6': buf[i] = 6;
                ++i;
                break;
            case '7': buf[i] = 7;
                ++i;
                break;
            case '8': buf[i] = 8;
                ++i;
                break;
            case '9': buf[i] = 9;
                ++i;
                break;
            }
        bool flag = true;
        while (flag){
            fscanf(fp,"%c", &c);
            switch (c) {
            case '1': buf[i] = 1;
                ++i;
                break;
            case '2': buf[i] = 2;
                ++i;
                break;
            case '3': buf[i] = 3;
                ++i;
                break;
            case '4': buf[i] = 4;
                ++i;
                break;
            case '5': buf[i] = 5;
                ++i;
                break;
            case '6': buf[i] = 6;
                ++i;
                break;
            case '7': buf[i] = 7;
                ++i;
                break;
            case '8': buf[i] = 8;
                ++i;
                break;
            case '9': buf[i] = 9;
                ++i;
                break;
            case '0': buf[i] = 0;
                ++i;
                break;
            case ' ': flag = false;
                ++i;
                break;
            case EOF: flag = false;
                ++i;
                break;
            case '\n': flag = false;
                ++i;
                break;
            case '\t': flag = false;
                ++i;
                break;
            }
            if ( i == cap_buf) {
                buf = (short*) realloc(buf, cap_buf * 2 * sizeof(short));
            }
        }
        --i;//сейчас ровно столько, сколько цифр в числе
        int length_of_tail = i % radix_size;
        int x;
        for (int j = i-1; j >= length_of_tail; j-= radix_size) {
            x = 0;
            for (int q = 0; q < radix_size; ++q){
                x += (pow((float)X,  (int)q) * buf[j - q]);
            }
            this->num.push_back(x);
        }
        x = 0;
        for (int j = 0; j < length_of_tail; ++j){
            x += (pow((float)X, (int) (length_of_tail -j-1)) * buf[j]);
        }
            if (x != 0) {
                this->num.push_back(x);

            }
        free(buf);
        return;
    }

    // ВЫВОД В КОНСОЛЬ
    void BigNum::output() {
        if (this->sign == false) {
            std::cout<<'-';
        }
        int size_of_vector = this->num.size_of_vector();
        for (int i = size_of_vector - 1; i >= 0; --i) {
            int w = radix / X;
            if (i != (size_of_vector - 1)) {
                int x = this->num[i];
                int z = (x / w);
                while ((z == 0)&&(w != 1)) {
                    w = w / X;
                    z = x / w;
                    std::cout<<'0';
                }
            }
                cout<<this->num[i];
        }
        cout<<'\n';
        return;
    }


    //ВЫВОД В ФАЙЛ - СОЗДАЁТ, ОТКРЫВАЕТ, ЗАКРЫВАЕТ
    void BigNum::foutput() {
        FILE * p = fopen ("OUTPUT.TXT", "w+");
        int size_of_vector = this->num.size_of_vector();
        for (int i = size_of_vector - 1; i >= 0; --i) {
            int w = radix / X;
            if (i != (size_of_vector - 1)) {
                int x = this->num[i];
                int z = (x / w);
                while ((z == 0)&&(w!=1)) {
                    w = w / X;
                    z = x/w;
                    fprintf(p,"%d", 0);
                }
            }
               fprintf(p, "%d", this->num[i]);
        }
        fclose(p);
        return;
    }

    //ВЫВОД В ФАЙЛ, НЕ ЗАКРЫВАЕТ
    void BigNum::foutput(FILE*  fp) {
        int size_of_vector = this->num.size_of_vector();
        for (int i = size_of_vector - 1; i >= 0; --i) {
            int w = radix / X;
            if (i != (size_of_vector - 1)) {
                int x = this->num[i];
                int z = (x / w);
                while ((z == 0)&&(w!=1)) {
                    w = w / X;
                    z = x/w;
                    fprintf(fp,"%d", 0);
                }
            }
               fprintf(fp, "%d", this->num[i]);
        }
        return;
    }

    //ВОЗВРАЩАЕТ МИНИМУМ ПО МОДУЛЮ
    BigNum BigNum::min_size (BigNum a, BigNum b) {
        a.sign = true;
        b.sign = true;
        if (a >= b) {
            return b;
        } else {
            return a;
        }
    }

    //ВОЗВРАЩАЕТ МАКСИМУМ ПО МОДУЛЮ
    BigNum BigNum::max_size (BigNum a, BigNum b) {   // по модулю!!!!!!
        a.sign = true;
        b.sign = true;
        if (a <= b) {
            return b;
        } else {
            return a;
        }
     }


    //УДАЛЯЕТ НЕЗНАЧАЩИЕ НУЛИ. ЕСЛИ ВСЕ НУЛИ, ОСТАВЛЯЕТ ОДИН НОЛЬ
    void BigNum::remove_null(){
        int k = this->num.size_of_vector() - 1;
        while ((this->num[k] == 0)&& (k > 0)) {
            this->num.remove_top();
            k = this->num.size_of_vector() - 1;
        }
        return;
    }

   //СЛОЖЕНИЕ
    BigNum  BigNum::operator + (BigNum a) {
        BigNum min_abs = min_size (*this, a); // минимальный по модулю
        BigNum max_abs = max_size(*this, a);// максимальный по модулю
        int min = min_abs.num.size_of_vector();
        int max = max_abs.num.size_of_vector();
        if ((min == 0)|| (max == 0)) {
            return max_abs;
        }
        BigNum sum;
        if (this->sign == a.sign) { //случай с одинаковым знаком слагаемых
           sum.sign = this->sign;
           int buf = 0;
           int x;
           for (int i = 0; i < min; ++i) {          //складываем в столбик пока не кончится короткое слагаемое
                x = (min_abs.num[i]) + max_abs.num[i] + buf;
                buf = x / radix;
                sum.num.push_back(x % radix);
           }

           for (int i = min; i < max; ++i) {       //переписывам с учётом переноса начало длинного слагаемого
                x = max_abs.num[i] + buf;
                buf = x / radix;
                sum.num.push_back (x % radix);
           }
           if (buf != 0) {                  //учёт последнего переноса
               sum.num.push_back(buf);
           }
        } else {                            //если знаки разные - вычитаем: ищем разницу абсолютных значений
                                           //и определяем знак результата
            max_abs.sign = true;
            min_abs.sign = true;
            sum = dif(max_abs, min_abs);
            sum.sign = max_abs.sign;
        }
        return sum;
    }

    //  РАЗНИЦА В АБСОЛЮТНЫХ ЗНАЧЕНИЯХ
    BigNum dif (BigNum max, BigNum min) {
        BigNum difference;
        int j = min.num.size_of_vector();
        for (int i = 0; i < j; ++i) {
             if(max.num [i] < min.num[i]) {     //"занимаем" у старшего разряда
                  max.num [i] += pow(10, radix_size);
                  max.num [i+1] -= 1;
             }
             difference.num.push_back(max.num [i] - min.num[i]);
        }
        for (int i = j; i < max.num.size_of_vector(); ++i){
            if (max.num[i] < 0) {
                max.num [i] += pow(10, radix_size);
                max.num [i+1] -= 1;
            }
            difference.num.push_back(max.num[i]);
        }

        difference.remove_null();

        if (difference.num.size_of_vector() == 0) {
            difference.num.push_back(0);
        }
        return difference;
    }



  // ОПЕРАТОР ПРИСВАИВАНИЯ

    void BigNum::operator = (BigNum a){
        this->sign = a.sign;
        this->num = a.num;
        return;
    }

    //      РАВНО

    bool BigNum::operator == (BigNum a){
        if (a.sign == this->sign) {
            if (a.num == this->num) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool BigNum::operator != (BigNum a) {
        return (!(a == *this));
    }

   //            БОЛЬШЕ ИЛИ РАВНО

    bool BigNum::operator >= (BigNum a) {
        if (a == *this) {
            return true;
        }
        if ((this->sign == false) && (a.sign == true)) {
            return false;
        }
        if ((this->sign == true) && (a.sign == false)) {
            return true;
        }
        int x = a.num.size_of_vector();
        int y = this->num.size_of_vector();
        if (y > x) { // учитывать только без незначащих нулей!!!
            return true;
        }
        if (y < x) {
            return false;
        }

        if (y == x) {
            for (int i = x-1; i >= 0; --i) {
                if (this->num[i] > a.num[i]) {
                    return true;
                }
                if (this->num[i] < a.num[i]) {
                    return false;
                }
            }
        return true;
        }
    }


 //            МЕНЬШЕ ИЛИ РАВНО
    bool BigNum::operator <= (BigNum a){
        if (a == *this) {
            return true;
        }
        if ((this->sign == true) && (a.sign == false)) {
            return false;
        }
        if ((this->sign == false) && (a.sign == true)) {
            return true;
        }
        int x = a.num.size_of_vector();
        int y = this->num.size_of_vector();
        if (y > x) { // учитывать только без незначащих нулей!!!
            return false;
        }
        if (y < x) {
            return true;
        }

        if (y == x) {
            for (int i = x-1; i >= 0; --i) {
                if (this->num[i] > a.num[i]) {
                    return false;
                }
                if (this->num[i] < a.num[i]) {
                    return true;
                }
            }
        return true;
        }
    }

//            БОЛЬШЕ
    bool BigNum::operator > (BigNum a) {
        return (!(this->operator <= (a)));
    }

//           МЕНЬШЕ
    bool BigNum::operator < (BigNum a) {
        return (!(this->operator >= (a)));
    }






#endif // BIGNUM_H
