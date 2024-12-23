//sheyuan.h

//Sample for room: ��԰
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_sheyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��԰");

	//add npcs into the room
	add_npc("animal_jinshe");/////////////////////////
	add_npc("animal_dushe");
	add_npc("animal_fushe");
	add_npc("animal_qingshe");
	add_npc("animal_wubushe");

	add_door("����ɽ��Է", "����ɽ��Է", "����ɽ��԰");

	set("long", "�����ǰ���ɽׯ����԰������ɽ�Զ��������£�����Ҫ�Ķ��ʾ����Զ��ߡ����������ߣ�ǽ��Ҳ�����ߣ�������Ҳ���´����ߣ���֦��Ҳ�������ߣ������㲻�ľ�");  

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
