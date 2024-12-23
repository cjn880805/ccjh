//clubpoem.h

//Sample for room: �����ָ�ʫ��
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_clubpoem);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ָ�ʫ��");


	add_npc("pub_xiaoer2");
	add_npc("pub_jiarenqi");
	
	add_door("�����ַ���¥����", "�����ַ���¥����", "�����ָ�ʫ��");
	add_door("����������", "����������", "�����ָ�ʫ��");
	add_door("�������ӷ�", "�������ӷ�", "�����ָ�ʫ��");
	add_door("��������", "��������", "�����ָ�ʫ��");

	set("long", "��¥֮�ϣ����Ƿ��������۵ס�����ɧ�Ͷ�ϲ��������Ʒ����ʫ��̸���۽����ƣ���֪˭�ڲ����ϸո�д��һ��ʫ(poem)����߹�̨��������������(qishi)���㲻�ɵ��߹�ȥ���˼��ۡ�" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


CHANGAN_END;
