//xiaoyao_feiling3.h ����֮�Ҽ���
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_feiling3);

virtual void create()
{
	set_name( "����֮�Ҽ���");
	set("no_autosave",1);
	set("index",3);

	add_item("shicheng");
	add_door("����֮�ұ���", "��ң�ȷ���֮�ұ���", "��ң�ȷ���֮�Ҽ���");
	add_door("��ң�ȷ���֮ñ", "��ң�ȷ���֮ñ", "��ң�ȷ���֮�Ҽ���");

};

XiaoYao_END;
