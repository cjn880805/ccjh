//xiaoyao_feiling1.h ����֮�����
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_feiling1);

virtual void create()
{
	set_name( "����֮�����");
	set("no_autosave",1);
	set("index",1);

	add_item("shicheng");
	add_door("����֮�����", "��ң�ȷ���֮�����", "��ң�ȷ���֮�����");
	add_door("����֮ñ", "��ң�ȷ���֮ñ", "��ң�ȷ���֮�����");

};

XiaoYao_END;
