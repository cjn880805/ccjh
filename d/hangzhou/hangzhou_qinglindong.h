//qinglindong.h

//Sample for room: 杭州清林洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_qinglindong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州清林洞");


	add_door("杭州飞来峰", "杭州飞来峰", "杭州清林洞");
	add_door("杭州翠微亭", "杭州翠微亭", "杭州清林洞");

	set("long","又叫老虎洞。只见靠右雕有弭陀，观音，大势至三尊小佛。洞口东侧壁上还刻着一组“庐舍那佛会”浮雕，它上刻花头龛，中间坐着释迦牟尼，左右分列文殊，普贤，还有天王佛像。西边是下山的路。小路往上延伸向东。" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
