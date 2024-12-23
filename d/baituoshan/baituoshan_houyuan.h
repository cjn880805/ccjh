//houyuan.h

//Sample for room: ����ɽ��Ժ
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_houyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��Ժ");

	//add npcs into the room
	add_npc("pub_zhangma");
	
	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ��Ժ");

	set("long", "����Ƨ���ĺ�Ժ��ס�š�ŷ���ˡ��������衺���衻.���������Ѹߣ����Ѿ����ɻ��ˣ������ﾲ��");

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
