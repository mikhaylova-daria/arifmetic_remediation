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
        if (this->num.size_of_vector() == 0) {
            this->num.push_back(0);
        }
        this->is_null();
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
        if (this->num.size_of_vector() == 0) {
            this->num.push_back(0);
        }
        this->is_null();
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
    BigNum BigNum::min_size (BigNum *_a, BigNum *_b) {
        BigNum a(*_a);
        BigNum b(*_b);
        a.sign = true;
        b.sign = true;
        if (a >= b) {
            return *_b;
        } else {
            return *_a;
        }
    }

    //ВОЗВРАЩАЕТ МАКСИМУМ ПО МОДУЛЮ
    BigNum BigNum::max_size (BigNum *_a, BigNum *_b) {   // по модулю!!!!!!
        BigNum a (*_a);
        BigNum b(*_b);
        a.sign = true;
        b.sign = true;
        if (a <= b) {
            return *_b;
        } else {
            return *_a;
        }
     }


    // АБСОЛЮТНОЕ ЗНАЧЕНИЕ
    BigNum BigNum::abs() {
        BigNum a(*this);
        a.sign = true;
        return a;
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


    //ОБРАБОТКА НУЛЯ

    bool BigNum::is_null() {
        bool answer = false;
        if (this->num.size_of_vector() == 1){
            if (this->num[0] == 0){
                this->sign = true;
                answer = true;
            }
        }
        return answer;
    }

   //СЛОЖЕНИЕ
    BigNum  BigNum::operator + (BigNum a) {
        BigNum min_abs = min_size (this, &a); // минимальный по модулю
        BigNum max_abs = max_size(this, &a);// максимальный по модулю
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

            sum = dif(max_abs, min_abs);
            sum.sign = max_abs.sign;
        }
        sum.is_null();
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
        difference.is_null();
        return difference;
    }



    //  ВЫЧИТАНИЕ

    BigNum BigNum::operator - (BigNum a) {
            BigNum difference;
            a.sign = !(a.sign);
            difference = *this + a;
            difference.is_null();
        return difference;
    }

    //  УМНОЖЕНИЕ НА НЕБОЛЬШОЕ
    BigNum BigNum::operator * (SMALLNUM a){

        BigNum product;
        if (this->sign == false){
                product.sign = false;
        }
        int buf = 0;
        int n = this->num.size_of_vector();
        for (int i = 0; i < n; ++i) {
            int x = this->num[i] * a + buf;
            buf = x / radix;
            product.num.push_back(x % radix);
        }
        if (buf != 0) {
            product.num.push_back(buf);
        }
        product.remove_null();
        product.is_null();
        return product;
    }

//УМНОЖЕНИЕ НА ДЛИННОЕ
    BigNum BigNum::operator * (BigNum a) {
        BigNum product;
        if (a.sign != this -> sign) {
            product.sign =false;
        }
        BigNum max = max_size(this, &a);
        BigNum min = min_size(this, &a);
        int n = min.num.size_of_vector();
        product = (max * (int) min.num[0]);
        for (int i = 1; i < n; ++i) {
            BigNum x = (max * (int) min.num[i]);
            for (int j = 0; j < i; ++j ){
                for (int f = 0; f < radix_size; ++f){
                     x = x * X;
                }
            }
            product = product + x;
        }
        product.remove_null();
        product.is_null();
        return product;
    }


    //  ЦЕЛАЯ ЧАСТЬ ОТ ДЕЛЕНИЯ
    BigNum BigNum::operator / (BigNum a){
        BigNum x;
        division(*this, a, x);
        return x;
    }

// ОСТАТОК ОТ ДЕЛЕНИЯ
    BigNum BigNum::operator % (BigNum a){
        BigNum x;
        return division(*this, a, x);
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


    //ДЕЛЕНИЕ ЧИСЕЛ ОДИНАКОВОЙ ИЛИ ОТЛИЧАЮЩЕЙСЯ НА 1 ДЛИНЫ (при попытки деления на 0 кидает строку "divide by 0")
    BigNum division_of_numbers_similar_length__return_modulo(BigNum dividend, BigNum divider, SMALLNUM &quotient) {
            long x;
            int y;
            if (divider.is_null()) {
                throw ("divide by 0");
                return divider;
            }
            BigNum intermediate;
            BigNum modulo;
            int dividend_size = dividend.num.size_of_vector();
            int divider_size = divider.num.size_of_vector();
            if (dividend_size == divider_size) {
                x = dividend.num[dividend_size - 1];
            }
            if (dividend_size == divider_size + 1) {
                x = dividend.num[dividend_size - 1] * radix + dividend.num[dividend_size - 2];
            }
            if (dividend_size < divider_size) {
                quotient = 0;
                return dividend;
            }

            y = divider.num[divider_size - 1];
            quotient = x / y;
            modulo = dividend - divider * quotient;
            if (quotient > 0) {
                BigNum null(0);
                while ((modulo < null) && (quotient > 0)) {
                    --quotient;
                    intermediate = divider * quotient;
                    modulo = dividend - intermediate;
                }
            }
            modulo.is_null();
            return modulo;
        }

//ДЕЛЕНИЕ ДЛИННОГО НА ДЛИННОЕ (при попытки деления на 0 кидает строку "divide by 0")

    BigNum division(BigNum dividend, BigNum divider, BigNum &quotient) {//Возвращает остаток, при делении на null кидает строку "null"
        BigNum one(1);
        if (divider.is_null()) {
            throw ("divide by 0");
            return divider;
        }
        if (dividend.abs() < divider.abs()) {
            quotient = null;
            return dividend;
        }
        if (dividend == divider){
            quotient = one;
            return null;
        }
        BigNum old_hat;
        BigNum new_hat;
        BigNum result;
        int current_num_of_quotient;
        int size_of_quotient;
        int size_dividend;
        int size;
        size = divider.num.size_of_vector();
        size_dividend = dividend.num.size_of_vector();
        int x = size_dividend;
        for (int i = 0; i < size; ++i) {
            old_hat.num.push_back(dividend.num[x - size + i]);
        }
        for (int i = 0; i < size; ++i) {
             dividend.num.remove_top();
             --size_dividend;
        }
        try {
            new_hat = division_of_numbers_similar_length__return_modulo(old_hat, divider, current_num_of_quotient);
        } catch (const char * caugh) {
            throw(caugh);
            return divider;
        }

        if (current_num_of_quotient == 0) {
            old_hat.num.put_on_bot (dividend.num[size_dividend - 1]);          // если шапка не поделилась  на делитель, дописываем разряд
            dividend.num.remove_top();
            --size_dividend;
            try{
               new_hat = division_of_numbers_similar_length__return_modulo(old_hat, divider, current_num_of_quotient);//пробуем поделить снова
            } catch (const char * caugh) {
                throw(caugh);
                return divider;
            }
        }
        size_of_quotient = size_dividend + 1;    // количество цифр в частном = количество цифр в делимом без шапки +1 (учитываем шапку)
        for (int i = 0; i < size_of_quotient; ++i) {
            result.num.push_back(0);
        }
        result.num [size_of_quotient - 1] = current_num_of_quotient;  //записали наибольший разряд частного
        int i;
        for (i = size_of_quotient - 2; i>=0; --i) {
            if (new_hat != null) {
                new_hat.num.put_on_bot(dividend.num[size_dividend - 1]);          //перенесли следующий разряд
            } else {
                new_hat.num[0] = dividend.num[size_dividend - 1];
            }
            --size_dividend;
            try {
                new_hat =  division_of_numbers_similar_length__return_modulo(new_hat, divider, current_num_of_quotient);
            } catch (const char * caugh) {
                throw(caugh);
                return divider;
            }
            result.num[i] = current_num_of_quotient;
        }
        quotient = result;
        if (dividend.sign == divider.sign) {
            quotient.sign = true;
        } else {
            quotient.sign = false;
        }
        quotient.is_null();
        new_hat.is_null();
        return new_hat;
    }




#endif // BIGNUM_H
