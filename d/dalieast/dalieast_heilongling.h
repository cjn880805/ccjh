//heilongling.h

//Sample for room: ����Ǻ�����
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_heilongling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǻ�����");

	set("resident", "������");

	add_npc("pub_xiaozei");
	add_npc("pub_daoke");       //add by zdn 2001-07-12

	add_door("������ּ�С��1", "������ּ�С��1", "����Ǻ�����");
	add_door("������ּ�С��2", "������ּ�С��2", "����Ǻ�����");
	add_door("�����������", "�����������", "����Ǻ�����");

	set("long", "���������к�÷���꣬���Ѱ�ʴ�ݾ��������Ƥ�����ʰ�쵣������ڵأ��������죬�罾�������壬���������������Ƭ��������巼Ϯ�ˣ���ֲ֪�Ժδ����ഫ��Ϊ��÷���ɻ�ȻҲ��������Ǻ���̶��" );
	
};


RESIDENT_END;
