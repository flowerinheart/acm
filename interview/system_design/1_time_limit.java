
//  实现一个类TestLimited, 类通过构造方法初始化int limitedTimes成员变量。
// 实现类的非静态成员方法qdsAllowed(),要求每秒钟qdsAllowed至多只能被调用limitedTimes次
// class TestLimited{
// int limitedTimes;
// TestLimited(int limitedTimes){
// this.limitedTimes=limitedTimes;
// }
// public void qdsAllowed(){
// doSomething();
// } 
// }


// 3.2 （继续3.1）当有多个线程来调用qdsAllowed,上述程序如何改进
// 我开始都没听懂啥意思，第一次做这么神奇的题想了好久心塞塞