//sheep.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_sheep);

virtual void create()
{
	set_name("Ұ��","sheep");

    set("gender", "����");
    set("race", "Ұ��");
    set("age", 2);
    set("long","��ֻҰ���ڵ�ͷ�Բݣ�������Ҳ�����ܡ�");
    set("combat_exp", 5000);
    set("shen_type", -1);
    set("attitude", "peaceful");

    set("water", 200);
    set("food", 200);

	CVector v;

	v.append("bite");
	v.append("knock"); 
	set("verbs", v);

    set("apply/attack", 10);
    set("apply/defense", 10);
};


NPC_END;
