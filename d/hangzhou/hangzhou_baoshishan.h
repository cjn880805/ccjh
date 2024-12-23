//baoshishan.h

//Sample for room: 杭州宝石山
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_baoshishan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州宝石山");

	CBox * box = Add_Box();
	box->add_object("eluanshi", 2);	
	box->set_name( "铁柜");	

	add_door("杭州青石大道8", "杭州青石大道8", "杭州宝石山");
	add_door("杭州保淑塔", "杭州保淑塔", "杭州宝石山");

	set("long"," 宝石山不是很高，山上多奇峰怪石。山路旁有一座亭子“来凤亭”，亭前有块卵形大石，临空搁置在山巅，叫落星石，又称寿星石。再往北上就到了保淑塔，往南下便回到大道了。");

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
