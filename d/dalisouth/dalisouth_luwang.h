//luwang.h

//Sample for room: ³����
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_luwang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "³����");

	set("resident", "ϲ��");

	//add npcs into the room
	add_npc("pub_tshangfan");
	
	add_door("�����ˮ��", "�����ˮ��", "�����³����");
	add_door("����Ǵ���¥", "����Ǵ���¥", "�����³����");
	add_door("�������������", "�������������", "�����³����");
	add_door("�������������", "�������������", "�����³����");

	set("long", "���������Ჿ��³�������Ჿ��̨�ģ��������и�����Խ�ݡ�����һ������ɽ���ϵ�С�򣬶���ͱ����Ǹ��ʵ�Ⱥɽ�����������������ɼ���ׯ�ͳ���" );
	
};


RESIDENT_END;
