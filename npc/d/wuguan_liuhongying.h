// wuguan_liuhongying.c

//code by Fisho
//date:2000-12-22

VENDOR_BEGIN(CNwuguan_liuhongying);

void create()
{
	set_name("лƽ��", "xie pingjing");
	set("title","��ţ��ݽ�ϰ");
	set("long", "л��ͷ����ݵ�������ϰ����ɱ�С����Ŷ�� ");
	set("gender", "Ů��");
	set("age", 17);
        set("icon",girl2);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("hammer", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
    set_inquiry("����", "�����Թſ���ޣ��˺������޾��ڣ�");
	carry_good("book2", 3);
}

int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

VENDOR_END;