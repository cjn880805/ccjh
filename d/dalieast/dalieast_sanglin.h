//sanglin.h

//Sample for room: �����ɣ��
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_sanglin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ɣ��");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_caisangnu");
	add_npc("pub_youwuyan");
	
	add_door("�����������", "�����������", "�����ɣ��");

	set("long", "һ��Ƭɣ���������ڵ�ɽ�Ļ���ɽ���ϡ����ϡ���˿�ǰ��������Ҫ��ҵ�����ĸ�Ů����֯˿����֯�Լ����ŵĶ�ȹ��Ҳ�������ٽ����佻��Щ������Ʒ��һȺ���Ĺ��������ּ�æ�Ų�ժɣҶ��" );

};

RESIDENT_END;
