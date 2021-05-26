fun main(args: Array<String>){
    val(a, x, y) = readLine()!!.split(' ').map(String::toInt)
        println(
            if (0 < x && x < a && 0 < y && y < a) 0
            else if ((0 > x || x > a) || (0 > y || y > a)) 2
            else 1
        )
}