//wulin_xianglengshanzhuang.h ����ɽׯ����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_xianglengshanzhuang);

virtual void create()			
{
	set_name("����ɽׯ����");

	add_npc("pub_zuo");
	add_npc("monster_36k");
	add_npc("monster_40k");
	add_npc("pub_jinshezunzhe");

	add_door("���괺�����","���괺�����", "���괺����ɽׯ����");
	add_door("���괺���η�","���괺���η�", "���괺����ɽׯ����");

};

WL_END;
