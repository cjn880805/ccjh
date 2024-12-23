//heshang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_heshang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("dali_enu");      //add by zdn 2001-07-20


	add_door("����Ǻӱ�", "����Ǻӱ�", "����Ǻ���");
	add_door("����ǲ�ɽɽ·", "����ǲ�ɽɽ·", "����Ǻ���");

	set("long", "���������ι�������ˮ֮�ϰٶ�ߵĿ��С�����һ������������֮���ţ������ִ��������һ������Ʒ�����Σ��Ų�����һ�����ַ�������������Ԯ�����������գ�ʵ���ϵ�Ҳ��ʮ�����ѡ�һ��ɽ��Ю�Ž��¼����ɽ���ˮ����������е�һ���⡣" );
	
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
