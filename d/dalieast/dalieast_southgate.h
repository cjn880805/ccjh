//southgate.h

//Sample for room: ���������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_southgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_bing");
	
	add_door("�������", "�������", "���������");
	add_door("����ǻ���·", "����ǻ���·", "���������");		
	add_door("������ּ�С��2", "������ּ�С��2", "���������");
	add_door("�����˫����", "�����˫����", "���������");
	
	set("long", "�˼��Ǵ����������ǵ����ţ������ʵ��������ǣ���گ�ڳ���������������������Ķ��ϵġ�������������Դ˳�Ϊ������ǽ��ʯ������ݳɣ��߶����壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲����������������ˣ�ż�����ʼ����μ����ɷ��ӡ�" );
	
};

RESIDENT_END;
