//suzhoucity.h

//Sample for room:  ����
//coded by Fisho
//data: 2000-11-3

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRsuzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_lady1");
	add_npc("pub_playboy");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_bing");                  //add by zdn 2001-07-15
	add_npc("helpnpc009");			//add by qzj 2001-08-13


	add_door("������ʯ�ٵ�2", "������ʯ�ٵ�2", "����");
	add_door("���ݺ�ɽ��", "���ݺ�ɽ��", "����");
	add_door("���ݶ���", "���ݶ���", "����");
	add_door("��������", "��������", "����");

	add_door("���ݸ���", "���ݸ���", "����");
	add_door("������Ժ", "������Ժ", "����");
	add_door("�����鳡", "�����鳡", "����");
	add_door("���ݿ͵�", "���ݿ͵�", "����");
	add_door("���ݲ��", "���ݲ��", "����");
	add_door("���ݱ�Ӫ", "���ݱ�Ӫ", "����");
//	add_door("������԰", "������԰", "����");
	add_door("�����Ͻ���", "�����Ͻ���", "����");
	add_door("����������", "����������", "����");
	add_door("���������", "���������", "����");
	add_door("����Ϸ԰��", "����Ϸ԰��", "����");
	add_door("����������", "����������", "����");
//	add_door("����ʨ����", "����ʨ����", "����");
	add_door("���ݱ�����", "���ݱ�����", "����");
	add_door("���ݾ۱�ի", "���ݾ۱�ի", "����");
	add_door("���ݴ���¥", "���ݴ���¥", "����");
	add_door("���ݴ�����", "���ݴ�����", "����");
	add_door("���ݱ��ͼ�", "���ݱ��ͼ�", "����");
	add_door("���ݲ���ͤ", "���ݲ���ͤ", "����");
	add_door("�����˺���ͷ", "�����˺���ͷ", "����");
	add_door("������̨ǰ�㳡", "������̨ǰ�㳡", "����");
};


ROOM_END;
