#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::cerr;

const int N = 10;

void main_f(int arr[N], bool bubbled, int counter);

int buttons();

void fill_arr(int arr[N]);

void fill_arr(int arr[N], int i);

void print_arr(int arr[N], int i);

void print_reverse(int arr[N], int i);

int arr_sum(int arr[N], int i);

void arr_sum(int arr[N]);

void bubble_sort(int arr[N], int i, int round);

void bubble(int arr[N], int i, int &round);

int binary(int arr[N], int i, int value);

void print_binary(int arr[N]);

int Arithmetic_progression(int arr[N], int i, int d);

int fibonachy(int arr[N], int i);

void fibonachy(int arr[N]);

int palindrom(int arr[N], int i);

void palindrom(int arr[N]);

int up_down(int arr[N], int i, int counter);

int up(int arr[N], int &i);

int down(int arr[N], int &i);

void print_up_down(int arr[N]);

int max(int arr[N], int high, int i, int max, bool was);

int maxim(int arr[N], int high, int i, int j, int &maxes);

void print_max(int arr[N], int high, int low);

bool is_firstly(int num, int i);

void firstly(int arr[N], int i);

//enum for menu
enum buttons_pattern {
    fill_pattern = 1,
    sum_pattern,
    bubble_pattern,
    binary_pattern,
    Arithmetic_pattern,
    print_pattern,
    print_reverse_pattern,
    fibonachy_pattern,
    palindrom_pattern,
    up_down_pattern,
    max_pattern,
    firstly_pattern,
    finish_pattern
};

int main() {

    int arr[N]{}, counter = 0;
    bool bubbled = false;

    main_f(arr, bubbled, counter);  //calling the menu function


    return EXIT_SUCCESS;

}

void main_f(int arr[N], bool bubbled, int counter) {
    int temp = buttons();
    enum buttons_pattern button;
    button = (enum buttons_pattern) temp;

    //*1*
    // input to arr
    if (button == fill_pattern) {
        fill_arr(arr);
        bubbled = false;
    }
    //*2*
    // finds the sum of the whole arr
    if (button == sum_pattern) {
        arr_sum(arr);
    }
    //*3*
    // bubble sort to the arr
    if (button == bubble_pattern) {
        int round = 0;
        bubble_sort(arr, 0, round);
        bubbled = true;
    }
    //*4*
    // binary search for value, only is the arr is already sort, if the value was found we print "1
    //else we print "0
    if (button == binary_pattern) {
        if (bubbled)
            print_binary(arr);
        else cerr << "Error\n" << endl;
    }
    //*5*
    // finds if the arr is making an arithmetic progression or not and print (1/0)
    if (button == Arithmetic_pattern) {
        int d = arr[0] - arr[1];
        cout << Arithmetic_progression(arr, 1, d) << endl;
    }
//*6*
// prints arr
    if (button == print_pattern)
        print_arr(arr, 0);
//*7*
// prints the arr from the end to the beginning
    if (button == print_reverse_pattern)
        print_reverse(arr, N - 1);
//*8*
// finds if every organ in the arr is the sum of the two organs that input right before him
    if (button == fibonachy_pattern) {
        fibonachy(arr);
    }
//*9*
// finds if the arr is making a symmetrical or not and print it (1/0)
    if (button == palindrom_pattern) {
        palindrom(arr);
    }
//*10*
// finds how many sub lines (up/ down) there ar inside the arr, and prints how many there are
    if (button == up_down_pattern) {
        print_up_down(arr);
    }
//*11*
// finds max number in range by the user input, and print it (if the input is un legal the program will search
//in range of the whole arr
    if (button == max_pattern) {
        int high = 0, low = 0;
        cin >> low >> high;
        print_max(arr, high, low);
    }
//*12*
// finds which numbers in the arr are firstly numbers and prints those by the original order
    if (button == firstly_pattern) {
        firstly(arr, 0);
    }
//*13*
// finishing function
    if (button == finish_pattern) {
        return;
    }

    counter++;

    if (counter <= 50) {
        main_f(arr, bubbled, counter);
    } else return;

}

//input for choose (1-13) function
int buttons() {

    int temp;
    cin >> temp;
    return temp;

}

//fill arr function
void fill_arr(int arr[N], int i) {
    if (i >= N)
        return;    //when it is the end of the arr stop

    cin >> arr[i];           //input
    fill_arr(arr, i + 1);      //calling function
}

//a cover for the fill_arr function
void fill_arr(int arr[N]) {
    fill_arr(arr, 0);
}

//as the name prints the arr
void print_arr(int arr[N], int i) {
    if (i >= N) {
        cout << endl;
        return;   //when it is the end of the arr stop
    }

    cout << arr[i] << " ";    //print each room in the arr
    print_arr(arr, i + 1);   //calling function over and over

}

//prints from the end to the beginning
void print_reverse(int arr[N], int i)  //print reverse
{
    if (i < 0) {
        cout << endl;
        return;   //if it is the end of the arr stop
    }

    cout << arr[i] << " ";  //print every room in the arr from the end to the beginning

    print_reverse(arr, i - 1);
}

//calculate the sum of the whole arr
int arr_sum(int arr[N], int i) {
    if (i == N - 1)
        return arr[i];    //if it is the *last* room in the arr stop

    return arr[i] + arr_sum(arr, i + 1);  //return the room i + arr room i_1


}

//cover for arr_sum function, printing it
void arr_sum(int arr[N]) {
    cout << arr_sum(arr, 0) << endl;
}

//bubble sort for arr
void bubble_sort(int arr[N], int i, int round) {
    if (i == N - 1)
        i = 0;   //when N-1 reset i

    bubble(arr, 0, round);     //call bubble function

    if (round == 0)   //if we did not make any change return, what is mean when the arr is sorted
        return;

    bubble_sort(arr, i + 1, 0);  //calling bubble_sort function till we return

}

//making the sort
void bubble(int arr[N], int i, int &round) {
    if (i == N - 1)
        return;    //if this is the last room in the ar

    if (arr[i] > arr[i + 1]) {    //if a0 > a1...
        int temp = arr[i + 1];    //save a0
        arr[i + 1] = arr[i];      //put a0 instead of a1
        arr[i] = temp;            //put in a1 instead of a0
        round++;                    //round=round +1 (saving actions, indication for the arr already sorted
    }

    bubble(arr, i + 1, round);   //calling function over nd over
}

//case for binary function
void print_binary(int arr[N]) {
    int value = 0;
    cin >> value;
    cout << binary(arr, (N - 1) / 2, value) << endl;   //print binary, starting in the half because the arr is sort
}
//binary search for value, only if the arr is already sort we will get in this function,
// i
int binary(int arr[N], int i, int value) {

    if (arr[i] == value)
        return 1;      //if we find the value return 1


    if (i == 0 || i == N - 1)
        return 0;      //if it is the end of the arr return 0

    if (value < arr[i]) {
        return binary(arr, i - 1, value);    //if value < current room call binary
    }

    if (value > arr[i]) {
        return binary(arr, i + 1, value);   //if value> current room call binary
    }
}

//checking arithmetic progression, d=determinate between a0 and a1
int Arithmetic_progression(int arr[N], int i, int d) {

    if (i == N - 1)
        return 1;


    if (arr[i] - arr[i + 1] != d)
        return 0;     //if one organ (A n, n=i) not makes the condition return 0

    return Arithmetic_progression(arr, i + 1, d);   //calling the function over and over
}

//finds id a2=a0+a1.., for each place
int fibonachy(int arr[N], int i) {
    if (i == 1)
        return 1;   //if this is the second room in the arr return 1

    if (arr[i] != arr[i - 1] + arr[i - 2])
        return 0;         //if some organ does not make the condition return 0

    return fibonachy(arr, i - 1);    //calling function over and over

}

//case for fibonachy int function, printing it
void fibonachy(int arr[N]) {
    cout << fibonachy(arr, N - 1) << endl;
}

//checking symethric
int palindrom(int arr[N], int i) {

    if (i == N / 2 + 1)
        return 1;     //if this is the half of the arr return 1

    if (arr[i] != arr[N - 1 - i])
        return 0;        //if some organ does not equal to it symethric organ return 0

    return palindrom(arr, i + 1);    //calling function

}

//case for palindrom function, printing
void palindrom(int arr[N]) {
    cout << palindrom(arr, 0) << endl;

}


int up_down(int arr[N], int i, int counter) {
    if (i < N - 1 && arr[i] == arr[i + 1])
        ++i;       //if we still smaller than the room 8 (there are 9 rooms),
    //and the value in current room equals to the value in the next room-> i=i+1

    if (i < N - 1 && arr[i] > arr[i + 1])
        counter += up(arr, i);              //if we still smaller than the room 8 (there are 9 rooms)
        // and the value in current room is bigger than
        // the value in the next room-> call up function
        // (saving how many sub series we have):
        // counter =up (finds each sub serie in arr)+counter
    else if (i < N - 1 && arr[i] < arr[i + 1])
        counter += down(arr, i);             //if we still smaller than the room 8 (there are 9 rooms)
    // and the value in current room is smaller than
    // the value in the next room-> call down function
    //(saving how many sub series we have):
    // counter =up (finds sub series in the arr) + counter

    if (i == N - 1) {
        return counter;      //when it is the last room in arr return
    }

    return up_down(arr, i, counter);    //calling function over and over until the exit condition
}

// finds down sub series, we already checked that this is a start of this serie so first of all we make i=i+1
int down(int arr[N], int &i) {
    i++;
    if (i == N - 1 || arr[i] > arr[i + 1])    //if its the end of the arr or this is not a down serie any more
        //what mean a(n)>a(n+1), return 1
        return 1;

    return down(arr, i);   //calling the function till the end condition
}

// finds up sub series, we already checked that this is a start of this serie so first of all we make i=i+1
int up(int arr[N], int &i) {
    i++;
    if (i == N - 1 || arr[i] < arr[i + 1])  //if its the end of the arr or this is not a down serie any more
        //what mean a(n)<a(n+1), return 1
        return 1;

    return up(arr, i);    //calling function till return

}

//case for up_down function, printing it
void print_up_down(int arr[N]) {
    int temp = 0;
    cout << up_down(arr, 0, temp) << endl;    //starting from room 0 in arr, and temp (counter)=0
}

//finds max organ in sub serie by range of input
int max(int arr[N], int high, int i, int maxes, bool was) {


    if (i < 0 || high >= N || i >= high || high <= 0 || i >= N) {    //un legal range,so we would check in the whole arr
        was = true;
        high = N - 1;      //reset range to the arr
        i = 0;              //""

        int j = i;          //definding index that equals to the low range
        maxes = maxim(arr, high, i, j, maxes);    //calling maxim (finding the max organ) by range of the whole arr
        //maxes=maxim (max organ)
        return maxes;                               //return max organ we have found
    }

    if (!was) {      //was=true, means the range are legal
        int j = i;      //definding index for low range
        maxes = maxim(arr, high, i, j, maxes);  //calling maxim (finding the max organ) by range of input
        return maxes;                                       //return max organ we have found
    }

    return maxes;           //default return
}

//finds the max organ by any range
int maxim(int arr[N], int high, int i, int j, int &maxes) {
    if (j > high)       //exit condition j is bigger that the high range
        return maxes;   //return maxes (biggest organ)
    if (arr[i] >= arr[j] && j <= high) {   //is we found bigger value, maxes=this value
        maxes = arr[i];

    } else if (j <= high)
        maxes = arr[j];
    return maxim(arr, high, i, j + 1, maxes);   //calling function over and over
}

//case for max function, printing the biggest we found
void print_max(int arr[N], int high, int low) {
    int maxes = 0;
    bool was = false;   //indication for legal/ un legal range

    cout << max(arr, high, low, maxes, was) << endl;   //print
}

//prints firstly numbers in arr
void firstly(int arr[N], int i) {
    if (i == N) {
        cout << endl;
        return;     //if ==N print new line and return
    }
    if (arr[i] != 2 && is_firstly(arr[i], arr[i] / 2))
        cout << arr[i] << " ";                   //if the current value is not 2, and is_firstly =true
    //with the current value print this value

    firstly(arr, i + 1);          //calling the function over and over

}

//finds firstly numbers
bool is_firstly(int num, int i)
{
    if (i == 1 || num == 1)     //if the divisor is 1 or the current value is 1 stop and return true
        return true;

    if (num == 0 || num % i == 0)   //if the current value is divide with any value between (1 - (current value/2) )
        // stop and return false
        return false;

    return is_firstly(num, i - 1);      //calling function over and over

}
