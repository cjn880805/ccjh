//hexi

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_hexi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	set("resident", "ϲ��");

	//add npcs into the room
	add_npc("pub_tshangfan");
	
	add_door("��������", "��������", "����Ǻ�����");
	add_door("�������������", "�������������", "����Ǻ�����");
	add_door("����������", "����������", "����Ǻ�����");
	add_door("������������ϰ�", "������������ϰ�", "����Ǻ�����");

	set("long", "���������������ϣ�ס���ǰ�޼�������Բ�����޼����̨�ģ�������˸����غ�������⣬��Ҫ�Բ���Ϊ�����ٺ����������������߲�Զ�����洬�����С��ͷ���ϱ�ɽ���в���Ұ�ޣ����Բ������Ӿ���ǰȥ���ԡ�" );
};

RESIDENT_END;
