//chaguan.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////

	add_door("������", "������", "���ݲ��");

	set("long", "��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�������������һ���ź��ſ����ǣ���̨������һλ�ϰ�����ڵ������̡�" );
 	set("resource/water", 1);
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
