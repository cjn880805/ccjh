//dalinorth.h

//Sample for room:  ����Ǳ���
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLiNorthcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǳ���");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("dali_guigongzi");           //add by zdn 2001-07-20 

	add_door("�������", "�������", "����Ǳ���");
	add_door("�����ɽ·3", "�����ɽ·3", "����Ǳ���");
	add_door("�����̫�ͳ�", "�����̫�ͳ�", "����Ǳ���");
	add_door("����Ƕ�ˮ��", "����Ƕ�ˮ��", "����Ǳ���");
	add_door("����ǲ軨ɽ1", "����ǲ軨ɽ1", "����Ǳ���");

	set("long","������ǣ���������ǣ��Ǵ�����Ķ��ǡ�����گ�ڳ������������ϡ�����͹��������ϡ������˹��������ϡ����������������������Ķ��ϵġ�������������Դ˳�Ϊ�����˴����Ǳ����ţ���÷ϪΪ���ӣ���ǽ����Ϫ�ϣ���ʯ������ݳɣ��߶����壬�����ɣ���������¥��פ�����ڡ���ʯ�ٵ��ӳ���ֱ�����죬����һ��������·����ͨȥ��");
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
