//zishanshizhe.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zishanshizhe);

virtual void create()
{
	set_name("×ÏÉÀÊÌÕß","zishanshizhe");
	
	set("icon", young_man1);
	set("gender", "ÄÐÐÔ" );
	set("age",18);
	set("class", "hemuya");
	set("combat_exp", 1000);
	set_skill("unarmed", 50);
	set_skill("dodge", 70);
	set_skill("force",100);
	set("force",300);
	set("max_force",300);
	
	carry_object("zichoushan")->wear();
	
};


NPC_END;
