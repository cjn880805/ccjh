//yanxiadong.h

//Sample for room: 杭州烟霞洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yanxiadong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州烟霞洞");
	
	add_npc("pub_daoke");             //add by zdn 2001-07-14


	add_door("杭州山路5", "杭州山路5", "杭州烟霞洞");
	add_door("杭州水乐洞", "杭州水乐洞", "杭州烟霞洞");

	set("long","据说站在山头，清晨观看山村缭绕炊烟，傍晚仰望蓝天彩霞，景色优美，故称“烟霞”。洞口两旁有精美的“观音”和“大势至菩萨”洞内两壁的天然岩穴里有各代的石刻。往东是下山的路。西边是去龙井。" );
    

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
