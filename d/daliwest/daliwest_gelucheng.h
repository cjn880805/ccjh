//gelucheng.h

//Sample for room: ��³��
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_gelucheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��³��");

	set("resident", "����");

	//add npcs into the room
//	add_npc("animal_shanyang");/////////////////////////
	add_npc("pub_muyangren");
	add_npc("baiyang");
	
	add_door("���������", "���������", "����Ǹ�³��");
//	add_door("���������", "���������", "����Ǹ�³��");
	add_door("�����ɽ��", "�����ɽ��", "����Ǹ�³��");

	set("long", "�˳����������������θ����������³�����ݡ��²�������Ĵ󡣸�����ɽ�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ���Ƥ���ʺϷ���ţ�򡣴�ȥ������������ɽ������ƽԭ�����д���" );
};

RESIDENT_END;
