//chahuashan6.h

//Sample for room: ����ǲ軨ɽ��
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_chahuashan6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǲ軨ɽ��");

	add_npc("pub_caichanu");   // add by zdn 2001-07-12
	add_npc("dali_huanu");       //add by zdn 2001-07-20

	add_door("����Ǵ��ˮ�ٲ�", "����Ǵ��ˮ�ٲ�", "����ǲ軨ɽ��");
	add_door("����ǲ軨ɽ5", "����ǲ軨ɽ5", "����ǲ軨ɽ��");

	set("long", "����ǲ軨ɽ�����棬��Ȼ�д����Ĳ軨ʢ���š�����Ȼ����ɽ�ϵ�Ʒ�ֺ��ˣ����Ƿ�Ʒ��" );
	
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
