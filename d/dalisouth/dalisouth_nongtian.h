//nongtian.h

//Sample for room: ũ��
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_nongtian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ũ��");

	set("resident", "ϲ��");

	//add npcs into the room
	add_npc("pub_nongfu1");
	add_item("daotian");
	
	add_door("������䶨��", "������䶨��", "�����ũ��");


	set("long", "һСƬ��ɽ���µ������￪�ѳ�����ũ�����Ϫ������ֲ��ˮ����̨������ܴ�̶�������ũҵ������ũҵ��ȴ�������Ǹ�Ů�����Ӵ�ר˾���ԺͲ��㡣" );
	
};

RESIDENT_END;
