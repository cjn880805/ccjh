//xiaoyao_dongmen.h ��ߧ���ض���
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_dongmen);

virtual void create()
{
	set_name( "��ߧ���ض���");
	set("no_autosave",1);
	set("long","ֻ�������ϵ�ɽʯ�У������ĸ����ɷ���Ĵ��֡���ߧ���ء���");

	add_door("��ߧ����", "��ң����ߧ����", "��ң����ߧ���ض���");
	add_door("�������������", "��ң�ȷ������������", "��ң����ߧ���ض���");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

XiaoYao_END;
