//chahuashan3.h

//Sample for room: ����ǲ軨ɽ3
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_chahuashan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǲ軨ɽ3");

	add_npc("dali_huanu");
	add_npc("pub_boy");     //add by zdn  2001-07-12 
	

	add_door("����ǲ軨ɽ2", "����ǲ軨ɽ2", "����ǲ軨ɽ3");

	set("long", "�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ���󲿷��Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���ǵ����ţ����߲�Զ�ǳ�ǽ��" );

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
