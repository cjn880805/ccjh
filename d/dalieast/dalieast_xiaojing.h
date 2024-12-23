//xiaojing.h

//Sample for room: �����ɽ��С��
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_xiaojing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ɽ��С��");

	add_npc("pub_playboy");    //add by zdn 2001-07-12

	add_door("����Ǵ��ˮ�ٲ�", "����Ǵ��ˮ�ٲ�", "�����ɽ��С��");
	add_door("����ǽ�֭����", "����ǽ�֭����", "�����ɽ��С��");

	set("long", "������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�������Ҷ������ϡ�ɡ������ౡ�����ϰϰ��" );
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
