#pragma ONCE

class Github {
    public:
        Github() {num = 0;}
        Github(int k) {num = k;}

        int getNum(int kk) {
            if (kk == 0) {
                return kk;
            }
            else {
                return kk-1;
            }
        }
    private:
        int num;
};