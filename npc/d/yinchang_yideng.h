// yinchang_yideng.c

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_yideng);

virtual void create()
{
    set_name("七灯大师", "yideng dashi");
    set("nickname",  "南帝"  );
    set("gender", "男性");
    set("age", 52);
    set("icon",old_man2);

    set("long", "他就是号称「南帝」的七灯大师，俗名段慧兴，现已逊位为僧。大师一生行善，积德无穷。");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
	
    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3500);
    set("max_mp", 3500);
    set("mp_factor", 100);
	
    set("combat_exp", 1500000);
    
	
    set_skill("force", 150);             // 基本内功
    set_skill("finger", 170);            // 基本指法
    set_skill("dodge", 150);             // 基本躲闪
    set_skill("parry", 150);             // 基本招架
    set_skill("liumai_shenjian", 200);   // 六脉神剑
    set_skill("taixuan_gong", 200);      // 太玄神功
    set_skill("lingxu_bu", 200);         // 凌虚步
    set_skill("literate",150);           // 读书识字
	
    map_skill("force"  , "taixuan_gong");
    map_skill("finger" , "liumai_shenjian");
    map_skill("dodge"  , "lingxu_bu");
    map_skill("parry"  , "liumai_shenjian");
	
    prepare_skill("finger", "liumai_shenjian");
	
    create_family("大理段家", 17, "弟子");
	
    carry_object("cloth")->wear();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	//一灯大师哈哈大笑，对着黄药师拱了拱手道：老爷子过奖了!
	command("nali huang");
	say(" 劲力内含，发之无形，伤人与不觉之中。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="huang-yaoshi")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;