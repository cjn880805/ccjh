//shulinwai.h

//Sample for room: �����������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_shulinwai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����������");

	set("resident", "������");

	add_npc("pub_playboy");
	add_npc("pub_playboy");          //add by zdn 2001-07-13

	add_door("����Ǻ�����", "����Ǻ�����", "�����������");

	set("long", "��������һƬ��ɭɭ��������ǰ��������ȥ����������Ķ�����ľ�����Ҿ�����������Լ�ɼ���ЩС·��������������ϸ�۲죬��������Ȼ�Ǹ�������Թ������а������а��ԣ����Ŷݼף��˵ķ�ͬС�ɣ�ǧ��ҪðȻ��ȥ��" );
};

RESIDENT_END;
