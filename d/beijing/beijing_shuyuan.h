//shuyuan.h

//Sample for room: ��Ժ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ժ");



	add_door("��������", "��������", "������Ժ");

	set("long", "��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫ʦ���Ͻ�ѧ���Ǿ��Ǿ��ǵĴ���������ˡ�������������������ѧ��ѧ����һ�Ź��ⰻȻ���鰸���ڹ�������ǰ�棬���ϰ��ż��������˵���װ�鼮���������������һ�����(shujia)�����ڶ��������ʯ�̣������Ժ��ʷ���ƾá�ֵ��һ�����Ƕ�ڽ���ǰ��ڵ�ѧ��(xuegui)��" );
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
