//fuzhoucity.h

//Sample for room:  ����
//coded by Fisho
//data: 2000-11-4


ROOM_BEGIN(CRfuzhoucity);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room

	add_door("��������", "��������", "����");
	add_door("�������д��", "�������д��", "����");

	add_door("����������", "����������", "����");
	add_door("����ӿȪ��", "����ӿȪ��", "����");
	add_door("����������", "����������", "����");
	add_door("����������", "����������", "����");
	add_door("�����ų���", "�����ų���", "����");
	add_door("����ζ��ζ", "����ζ��ζ", "����");
	add_door("�����ᶽ����", "�����ᶽ����", "����");
	add_door("���ݸ����ھ�", "���ݸ����ھ�", "����");

};


ROOM_END;
