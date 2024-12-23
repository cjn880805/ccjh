//heimuya_zishan.h 
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_zishan);

virtual void create()
{
	set_name("×ÏÉÀÊÌÕß", "zishan shizhe");
	set("gender", "ÄÐÐÔ" );
	set("age",18);
	set("class", "hemuya");
	set("icon",young_man4);
	set("combat_exp", 1000);
	set_skill("unarmed", 50);
	set_skill("dodge", 70);
	set_skill("force",100);
	set("force",300);
	set("max_force",300);

//	carry_object("zichoush")->wear();
}

NPC_END;