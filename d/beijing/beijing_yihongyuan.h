//yihongyuan.h

//Sample for room: ����Ժ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_yihongyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժ");

	//add npcs into the room
	add_npc("pub_guigong");
	
	add_door("��������", "��������", "��������Ժ");
	add_door("��������Ժ��¥", "��������Ժ��¥", "��������Ժ");

	set("long", "��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ���Ӿ�����������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ�������������������Ů�˷�վ���Զ��㷢����Ц��һ���������æ��ǰ�к����ˡ���¥�ϴ���������������ε�������" );
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
