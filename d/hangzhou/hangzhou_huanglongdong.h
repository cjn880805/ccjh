//huanglongdong.h

//Sample for room: ���ݻ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_huanglongdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݻ�����");

	//add npcs into the room
	add_npc("animal_dushe");
	
	add_door("����ɽ·8", "����ɽ·8", "���ݻ�����");

	set("long"," һ��ɽ�ţ����򽻴䣬���ж��졣ʯ�ڶ�����̦�۳��̣�������֮����һС�壬���⣺���������顱��");
    

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
