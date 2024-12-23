//dianchi.h

//Sample for room: ����ǵ��
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_dianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǵ��");

	add_npc("pub_youke");
	add_npc("pub_cunfu");   // add by zdn 2001-07-12 
	add_npc("pub_yaoyue");

	add_door("������سص̰�1", "������سص̰�1", "����ǵ��");

	set("long", "������ܵ�ɽ����������ɽϵ������ɽ���Ķ�֧�������£��ܳ�����ɽ���д�С��ʮ��ɽ�塣���������ɽ���£�ɽ��ˮ���������Ӱ��������Ȼ��ͼ������صġ��ᡱ�������м��Ǵ���ӣ���˾��Ǩ�ġ�ʷ�ǡ��������д������أ��ڹŴ�������һ���������Ĳ������ƣ�������ء�" );
	
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
