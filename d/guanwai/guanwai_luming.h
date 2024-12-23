//luming.h

//Sample for room: ¹����
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_luming);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "¹����");

	set("monster_chance", 5);
	//add npcs into the room
//	add_npc("animal_buck");/////////////////////////
//	add_npc("animal_doe");
	add_npc("pub_diaoyu");

	add_door("�������ŷ�", "�������ŷ�", "����¹����");
	add_door("������Ʒ�", "������Ʒ�", "����¹����");

    set("long","���ŷ��������¹���塣¹�����ֳ�֥�̷壬�������һ�ݵ��ӣ���Բ��ǣ��������ӵ���ð����ÿ���϶������������ѩ����Ψ¹������Ȼֲ��ïʢ����ʢ��֥�ݣ�¹���֮�����кס�ȸ������������ϣ��С�¹����ȣ����֥�ǡ�֮�ơ�" );
    

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
