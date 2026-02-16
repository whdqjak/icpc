백준 단계별로 풀어보기 매일 한단계씩 복습 정리.

백준 단계별로 풀어보기 매일 한문제 이상씩 풀기

처음보는 내용 있으면 문제를 먼저 풀기보단 이론 공부먼저 하기





vs code
ubuntu기반 c++환경 만들기

wsl 깔기(우분투 포함)

wsl --install

wsl 터미널 열어서 컴파일러 깔기

sudo apt update
sudo apt install -y build-essential gdb

vscode 터미널에서 icpc파일 만들기

cd ~
mkdir icpc	
cd icpc
code .

pwd(현재경로확인)
cd /경로/쓰면/된다
code .(파일 열기)

추가로 git에서 clone하고 싶으면
git clone 주소


git pull
git add .
git commit -m "하고싶은말"
git push


run() {
    if [ -z "$1" ]; then
        echo "사용법: run 파일이름.cpp"
        return 1
    fi

    g++ -std=gnu++17 -O2 -Wall "$1" -o main && ./main
}
source ~/.bashrc

// run main.cpp
