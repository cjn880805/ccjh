//xizhou.h

//Sample for room: ϲ�ݳ�
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_xizhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ϲ�ݳ�");

	set("resident", "ϲ��");

	//add npcs into the room
	add_npc("pub_keshang");
	add_npc("dali_keshang");       //add by zdn 2001-07-20
	
	add_door("����ǿ͵�", "����ǿ͵�", "�����ϲ�ݳ�");
	add_door("�����������", "�����������", "�����ϲ�ݳ�");
	add_door("���������С·", "���������С·", "�����ϲ�ݳ�");
	add_door("�������������", "�������������", "�����ϲ�ݳ�");

	set("long", "ϲ���������ǣ��Ǵ����ϲ���ǣ����ƴ��Ѽ����٣��ؾ��˻����ڣ���ó�����٣��д��������������˽��ף��ɹ�������Ľ�����˿֯Ʒ��������Ƥë�ȣ�������������ӡ�ȵĿ�����࣬ǰ����˿������˹������Զ��������" );
};


RESIDENT_END;
